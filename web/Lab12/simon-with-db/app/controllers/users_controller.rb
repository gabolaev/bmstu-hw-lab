class UsersController < ApplicationController
  before_action :set_user, only: [:show, :edit, :update, :destroy]
  skip_before_action :logged_in, only: [:new, :create]

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

  def destroy
    session[:user_id] = nil if same_user
    @user.destroy
    redirect_to root_path, notice: 'User was deleted'
  end

  def update
    permitted = params.require(:user).permit(:password, :password_confirmation, :old_password)

    if @user.update(permitted)
      redirect_to @user, notice: 'Password changed successfully'
    else
      render :edit
    end
  end

  def show; end

  def edit; end

  def index
    @users = User.all
  end

  private

  def allowed_params
    params.require(:user).permit(:username, :password, :password_confirmation)
  end

  def set_user
    @current_user = @current_user
    @user = User.find(params[:id])
  end

  def validate_edit
    unless same_user
      redirect_to users_path, notice: "You're not allowed to edit this user"
    end
  end

  helper_method :same_user

  def same_user
    @user == @current_user
  end
  protected

  def construct_params
    params.require(:user).permit(:username, :password, :password_confirmation)
  end
end
