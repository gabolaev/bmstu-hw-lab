require 'test_helper'

class AuthControllerTest < ActionDispatch::IntegrationTest
  test "should get signin" do
    get auth_signin_url
    assert_response :success
  end

  test "should get signout" do
    get auth_signout_url
    assert_response :success
  end

end
