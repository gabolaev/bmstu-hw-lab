require 'nokogiri'
doc = Nokogiri::XML(File.read('success.xml'))
xslt = Nokogiri::XSLT(File.read('transform.xslt'))
puts xslt.transform(doc)
