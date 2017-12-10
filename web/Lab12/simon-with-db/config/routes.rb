Rails.application.routes.draw do

  get 'auth/new'

  resources :users
  resources :auth

  post 'auth/create'

  get 'signup', to: 'users#new', as: 'signup'
  get 'signin', to: 'auth#new', as: 'signin'
  get 'signout', to: 'auth#destroy', as: 'signout'

  root to: 'simon_with_db#input'

  post 'users/create'
  post 'simon_with_db/output'

  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end
