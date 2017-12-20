require 'test_helper'

class UserTest < ActionDispatch::IntegrationTest

  test 'calc requires login' do
    post simon_with_db_output_path, params: { m: 10 }
    assert_redirected_to signin_path
  end

  test 'can get root after sign in' do
    post auth_create_url, params: { username: 'user_for_tests', password: 'testtest' }

    get root_path
    assert_response :success
  end

  test 'should create users' do
    old_count = User.count
    post users_path, params: { user: { username: 'hey_now_you', password: 'are_an_all-star' } }
    new_count = User.count
    assert new_count > old_count
  end

end