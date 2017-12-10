class ChangeDataTypeForResultValue < ActiveRecord::Migration[5.1]
  def change
    change_column :simon_factorials, :result_value, :text
  end
end
