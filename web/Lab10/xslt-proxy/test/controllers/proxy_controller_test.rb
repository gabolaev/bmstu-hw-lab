require 'test_helper'

class ProxyControllerTest < ActionDispatch::IntegrationTest

  test "should get output" do
    get proxy_output_url params: { to_value: 7, side: 'client_with_xslt'}
    assert_response :success
  end

  test "should return various results" do
    get proxy_output_url params: { to_value: 3, side: 'client_with_xslt' }
    result1 = response.parsed_body

    get proxy_output_url params: { to_value: 4, side: 'client_with_xslt' }
    result2 = response.parsed_body

    assert_not_equal result1, result2
  end

  test 'should return XML' do
    get proxy_output_url, params: { to_value: 4, side: 'client' }
    xml = Nokogiri::XML(response.parsed_body)
    value = xml.search('for-fact').children.first.text
    assert_equal '6.0', value
  end

  test 'should return HTML' do
    get proxy_output_url, params: { to_value: 4, side: 'server' }
    assert_select 'p', count: 4
  end
end
