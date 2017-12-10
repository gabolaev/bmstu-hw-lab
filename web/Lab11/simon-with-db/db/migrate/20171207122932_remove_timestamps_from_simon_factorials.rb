class RemoveTimestampsFromSimonFactorials < ActiveRecord::Migration[5.1]
  def change
    remove_column :simon_factorials, :created_at, :string
    remove_column :simon_factorials, :updated_at, :string
  end
end
