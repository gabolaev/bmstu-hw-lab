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
    assert_equal "тедавте видел огромное яблеке та столе",
                 string_handler("недавно видел огромное яблоко на столе")
    assert_equal "иногда перемены к худшему",
                 string_handler("иногда перемены к худшему")
  end

end
