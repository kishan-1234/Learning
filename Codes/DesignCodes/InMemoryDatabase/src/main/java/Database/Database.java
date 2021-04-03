package Database;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Database {

    private String name;
    private Map<String, Table> tableMap = new HashMap<>();

    public Database(String databaseName) {
        this.name = databaseName;
    }

    public Table createTable(String tableName, List<Column> columns) {

        if(checkIfTableExists(tableName)) System.err.println("TableName: "+ tableName+" already exists!");
        Table table = new Table(tableName, columns);
        tableMap.put(tableName, table);
        return table;
    }

    public void dropTable(String tableName) {

        if(!checkIfTableExists(tableName)) return;
        tableMap.remove(tableName);
        System.out.println("TableName: "+tableName+" dropped!");
        return;
    }

    public void truncate(String tableName) {

        if(!checkIfTableExists(tableName)) return;
        Table table = tableMap.get(tableName);
        table.truncateRows();
    }

    private Boolean checkIfTableExists(String tableName) {

        if(!tableMap.containsKey(tableName)) {
            System.err.println("TableName: "+tableName+" does not exists");
            return false;
        }
        return true;
    }
}
