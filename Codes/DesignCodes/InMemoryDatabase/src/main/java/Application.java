import Database.Database;
import Database.Column;
import Database.Table;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Application {

    public static void main(String[] args) {

        String tableName = "Employee";
        Column name = new Column("name", Column.Type.STRING);
        Column age = new Column("age", Column.Type.INT);
        Column salary = new Column("salary", Column.Type.INT);
        Database db = new Database("MyDB");
        List<Column> columns = new ArrayList();
        columns.add(name);
        columns.add(age);
        columns.add(salary);
        Table table = db.createTable(tableName,columns);
        Map<Column,Object> columnValues = new HashMap ();
        columnValues.put(name, "John");
        columnValues.put(age, 25);
        columnValues.put(salary, 10000);

        table.insertRow(columnValues);
        columnValues.clear();
        columnValues.put(name, "Kim");
        columnValues.put(age, 28);
        columnValues.put(salary, 12000);
        table.insertRow(columnValues);
        table.printRows();
        table.getRecordsByColumnValue(age, 28);
        table.getRecordsByColumnValue(name, "John");
        db.truncate("Employee");
        table.printRows();
    }
}
