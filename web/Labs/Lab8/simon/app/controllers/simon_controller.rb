class SimonController < ApplicationController
  def input
    render :input
  end

  def output
    if params[:to_value].to_i < 0 || params[:to_value].to_i > 15
      @results = 'Указан неверный формат числа'
      @error = true
    else
      @for_facts = []
      @error = false
      @iters = {}
      @results = []
      all_digits = (1..(params[:to_value].to_i)).to_a
      all_digits[2..(params[:to_value].to_i - 1)].each_with_index do |value, index|
        factorial = (1..value).inject(:*).to_f
        @for_facts[index] = factorial
        @iters[index] = {}
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
    end

    respond_to do |format|
      format.html
      format.json do
        render json: { type: @results.class.to_s, value: @results}
      end
    end
  end
end
