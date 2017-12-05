require 'test_helper'

class SimonControllerTest < ActionDispatch::IntegrationTest
  test 'should get input' do
    get simon_input_url
    assert_response :success
  end

  test 'should get output' do
    get simon_output_url
    assert_response :success
  end

  test 'should get error for view with 20' do
    get simon_output_url params: { to_value: 20 }, headers: {}
    assert_equal assigns[:error], true
  end

  test 'should return normal result' do
    get simon_output_url params: { to_value: 12 }, headers: {}
    assert_equal assigns[:results], [6.0, 24.0, 120.0, 720.0]
  end
end
