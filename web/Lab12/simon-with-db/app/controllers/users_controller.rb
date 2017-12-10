class UsersController < ApplicationController
  def new
    @user = User.new
  end

  def create
    @user = User.new(construct_params)
    if @user.save
      session[:user_id] = @user.id
      redirect_to root_url
    else
      redirect_to signup_path
      flash[:message] = 'Неверный формат введённых данных'
    end
  end

  protected

  def construct_params
    params.require(:user).permit(:username, :password, :password_confirmation)
  end
end
