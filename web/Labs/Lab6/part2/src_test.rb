require 'minitest/autorun'
require './src'

# i hate you rubocop
class MyTest < MiniTest::Test
  def test_ok
    assert_equal 0.3678571428571429, find_with_precision_enum(10e-5)
  end

  def test_fail
    assert_raises TypeError do
      find_with_precision_enum 'energo'
    end
  end
end
