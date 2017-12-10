class ChangeUniqueForSimonFactorialsId < ActiveRecord::Migration[5.1]
  def change
    add_index :simon_factorials, :id, unique: true
  end
end