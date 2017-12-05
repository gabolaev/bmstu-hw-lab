require 'minitest/autorun'
require './part1/src'

# This class is really wonderful
class Test < MiniTest::Test
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
    assert_equal 140.00, calculate(5)
    assert !(calculate(0).infinite?.nil?)

  end

  # Fake test
  def test_fail
    assert_raises TypeError do
      calculate 'hello'
    end
  end
end
