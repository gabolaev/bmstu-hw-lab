module SimonWithDbHelper
  def find_factorials(to_value)
    @for_facts = []
    @iters = []
    @results = []
    all_digits = (1..to_value).to_a
    all_digits[2..(to_value - 1)].each_with_index do |value, index|
      factorial = (1..value).inject(:*).to_f
      @for_facts[index] = factorial
      @iters[index] = []
      local_index = index
      a = all_digits[index]
      b = a + 1
      c = b + 1
      composition = a * b * c
      while composition <= factorial
        @iters[index][local_index] = "#{a} * #{b} * #{c} = #{composition}"
        if composition == factorial
          @results[index] = factorial
          break
        end
        local_index += 1
        a = b
        b = c
        c += 1
        composition = a * b * c
      end
    end
    {results: @results, for_facts: @for_facts, iters: @iters}
  end
end
