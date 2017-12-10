class ChangeUniqueForSimonFactorials < ActiveRecord::Migration[5.1]
  def change
    add_index :simon_factorials, :input_value, unique: true
  end
end
