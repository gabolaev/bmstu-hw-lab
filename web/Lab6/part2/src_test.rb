require 'minitest/autorun'
require_relative './src'

# i hate you rubocop
class MyTest < MiniTest::Test
  def test_ok
    assert_equal 0.3678571428571429, find_with_precision_enum(10e-5)
  end

  def test_delta
    [1e-2, 1e-3, 1e-4, 1e-5, 1e-6, 1e-7, 1e-8, 1e-9].each do |p|
      assert_in_delta (1 / Math::E), find_with_precision_enum(p), p
    end
  end

  def test_fail
    assert_raises TypeError do
      find_with_precision_enum 'energo'
    end
  end
end
