require 'minitest/autorun'
require_relative '../part2/src'

# tests of relatives and values
class MyTest < MiniTest::Test
  def test_relatives
    assert_kind_of Point, Circle.new(10, 30, 10)
  end

  def test_value_rad
    assert_equal 10, Circle.new(10, 30, 10).center_rad
  end

  def test_value_x
    assert_equal 8.66, Circle.new(10, 30, 10).cartesian_x
  end

  def test_value_y
    assert_equal 5.0, Circle.new(10, 30, 10).cartesian_y
  end

  def test_fail_privacy
    assert_raises NoMethodError do
      Circle.new(10, 30, 10).rad
    end
  end
end
