class XmlController < ApplicationController
  include XmlHelper

  before_action :check_params, only: :index

  def index
    data = if @error.nil?
             find_factorials(@to_value)
           else
             { message: "Неверный формат входных данных. Значение = #{@to_value}"}
           end

    respond_to { |format|
      format.rss { render xml: data.to_xml }
      format.xml { render xml: data.to_xml }
    }
  end

  protected

  def check_params

    @to_value = params[:to_value]
    if @to_value =~ /^[0-9]+$/
      @to_value = @to_value.to_i
      @error = true if @to_value <= 2 || @to_value > 15
    else
      @error = true
    end
  end
end
