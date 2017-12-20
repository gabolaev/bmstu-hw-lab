class AddNotNullToUsername < ActiveRecord::Migration[5.1]
  def change
    change_column :users, :username, :string, null: false
  end
end
