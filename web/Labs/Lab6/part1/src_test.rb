require 'minitest/autorun'
require_relative './src'

# tests
class MyTest < MiniTest::Test

  def test_delta
    [1e-2, 1e-3, 1e-4, 1e-5, 1e-6, 1e-7, 1e-8, 1e-9].each do |p|
      assert_in_delta (1 / Math::E), find_with_precision_no_enum(p), p
    end
  end

  def test_fail
    assert_raises TypeError do
      find_with_precision_no_enum 'energo'
    end
  end
end
