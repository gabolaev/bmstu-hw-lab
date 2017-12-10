require 'test_helper'

class SimonWithDbControllerTest < ActionDispatch::IntegrationTest

  test "results should be different" do
    post simon_with_db_output_url params: { to_value: 5 };
    result1 = response.parsed_body

    post simon_with_db_output_url params: { to_value: 6 };
    result2 = response.parsed_body

    assert_not_equal result2, result1

  end
end
