require 'test_helper'

class XmlControllerTest < ActionDispatch::IntegrationTest

  test 'should get input' do
    get root_url params: { to_value: 5, format: 'xml' }
    assert_response :success
  end
end
