class SimonWithDbController < ApplicationController
  include SimonWithDbHelper

  before_action :check_params, only: :output
  before_action :check_login, only: :output

  def input; end

  def output

    rsp = if @error
            "{:message=>\"Неверный формат входных данных. Значение = #{@to_value}\"}"
          else
            prepare = SimonFactorial.find_by input_value: @to_value
            if prepare.nil?
              prepare = SimonFactorial.create(input_value: @to_value, result_value: find_factorials(@to_value))
            end
            prepare.result_value
          end

    # render xml: eval(rsp).to_xml
    dump_in_xml
  end

  protected

  def check_params

    @to_value = params[:to_value]
    if @to_value =~ /^[0-9]+$/
      @to_value = @to_value.to_i
      @error = true if @to_value <= 2 || @to_value > 15
    else @error = true
    end
  end

  def check_login
    unless logged_in?
      redirect_to '/signup'
    end
  end

  def dump_in_xml

    final_hash = {}
    result = SimonFactorial.all
    result.each_with_index { |p|
      final_hash.merge!(eval(p.result_value))
    }
    render xml: final_hash.to_xml
  end
end