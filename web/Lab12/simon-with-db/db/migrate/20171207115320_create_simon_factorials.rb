class CreateSimonFactorials < ActiveRecord::Migration[5.1]
  def change
    create_table :simon_factorials do |t|
      t.integer :input_value
      t.string :result_value

      t.timestamps
    end
  end
end
