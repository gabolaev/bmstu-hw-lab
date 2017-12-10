class UsersController < ApplicationController

  before_action :check_params

  def new
    @user = User.new
  end

  def create
    @user = User.new(construct_params)
    if @user.save
      session[:user_id] = @user.id
      redirect_to root_url
    else
      render :new
    end
  end

  protected

  def construct_params
    params.require(:user).permit(:username, :password, :password_confirmation)
  end

  def check_params
    p params[:password_confirmation]
    redirect_to '/signup' if params[:password] != params[:password_confirmation]
  end
end
