<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/">
    <xsl:choose>
      <xsl:when test="/*/message">
        <h2>
          <xsl:value-of select="."/>
        </h2>
      </xsl:when>
      <xsl:otherwise>
        <h2>Количество найденых факториалов:
          <xsl:value-of select="count(/*/results/*)"/>
        </h2>
        <xsl:for-each select="/*/results/result">
          <p>
            <xsl:value-of select="."/>
          </p>
        </xsl:for-each>
        <table>
          <xsl:for-each select="/*/for-facts/for-fact">
            <xsl:variable name="ffPos" select="position()"/>
            <tr>
              <td><xsl:value-of select="$ffPos + 2"/>! =
                <xsl:value-of select="."/>
              </td>
              <td>
                <xsl:for-each select="/*/iters/iter[$ffPos]/iter[not(@nil='true')]">
                  <p>
                    <xsl:value-of select="."/>
                  </p>
                </xsl:for-each>
              </td>
            </tr>
          </xsl:for-each>
        </table>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
</xsl:stylesheet>
