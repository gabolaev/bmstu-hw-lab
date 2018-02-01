require 'test_helper'

class AuthControllerTest < ActionDispatch::IntegrationTest
  test 'should get signin' do
    get signin_path
    assert_response :success
  end

  test 'should get signout' do
    get signout_path
    assert_response :success
  end
end
