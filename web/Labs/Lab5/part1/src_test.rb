require 'minitest/autorun'
require './src'

# Shut up rubocop
class SquareTest < MiniTest::Test
  # Called before every test method runs. Can be used
  # to set up fixture information.

  def setup
    # Do nothing
  end

  # Called after every test method runs. Can be used to tear
  # down fixture information.

  def teardown
    # Do nothing
  end

  def test_ok
    calc_for_ok = Calculator.new
    assert_equal 140.00, calc_for_ok.calculate(5)
  end

  # Fake test
  def test_fail
    calc_for_fail = Calculator.new
    assert_raises TypeError do
      calc_for_fail.calculate 'hello'
    end
  end
end
