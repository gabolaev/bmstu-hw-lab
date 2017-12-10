Rails.application.routes.draw do
  root to: 'simon_with_db#input'

  post 'simon_with_db/output'
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end
