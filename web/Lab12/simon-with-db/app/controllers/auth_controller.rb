class AuthController < ApplicationController

  def new
  end

  def create
    user = User.find_by(username: params[:username])
    if user && user.authenticate(params[:password])
      session[:user_id] = user.id
      redirect_to root_url, message: 'Welcome back'
    else
      flash[:message] = 'Неверное имя пользователя или пароль'
      redirect_to signin_url
    end
  end

  def destroy
    session[:user_id] = nil
    redirect_to root_url
  end
end
