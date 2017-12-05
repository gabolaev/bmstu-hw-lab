require 'minitest/autorun'
require_relative '../part3/src'
# 1488
class Test < MiniTest::Test
  def test_ok
    assert_in_delta 1.1254220002893505, calc_integral(0, 1) { |x|
      Math.exp(x) / (x + 1)
    }
    assert_in_delta 0.6670667399999997, calc_integral(0, 2, ->(x) { x * (x - 1) })
  end

  def test_fail
    assert_raises NoMethodError do
      calc_integral('a', 'b')
    end
  end
end
