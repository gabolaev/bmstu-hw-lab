require 'test_helper'

class SimonFactorialTest < ActiveSupport::TestCase
  test 'the truth' do
    assert true
  end

  test 'should test inserting' do
    SimonFactorial.create(input_value: 42, result_value: 'this is the answer to everything')
    assert_equal 'this is the answer to everything', SimonFactorial.find_by_input_value(42).result_value;
  end

  test 'should not insert twice' do
    SimonFactorial.create(input_value: 42, result_value: 'This is the answer to everything')
    assert_raise ActiveRecord::RecordNotUnique do
      SimonFactorial.create(input_value: 42, result_value: 'I\'m plagiarized')
    end
  end
end
