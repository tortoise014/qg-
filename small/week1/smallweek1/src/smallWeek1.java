import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.io.FileInputStream;
import java.io.IOException;
import java.sql.*;
import java.util.Properties;

public class smallWeek1 {
    static Connection conn=null;
    Statement statement=null;
    static {
        Properties prop = new Properties();

        try {
            prop.load(new FileInputStream("src/druid.properties"));
            //获取连接池对象
            DataSource dataSource = DruidDataSourceFactory.createDataSource(prop);

            //获取数据库连接
            conn = dataSource.getConnection();
        } catch (IOException | SQLException e) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
    /**
     * @param resultSet : 结果集（DQL产生）
     * @param statement : Statement接口或PreparedStatement接口的实现类
     * @param connection : 即通过getConnection方法获取到的连接



     */
    public static void close(ResultSet resultSet, Statement statement, Connection connection) {
        /*
            DML的执行不产生ResultSet结果集，可以传入一个null;
            因此要先判断传入的对象是否为空，若非空则调用close方法关闭资源（动态绑定）
         */
        try {
            if (resultSet != null) {
                resultSet.close();
            }
            if (statement != null) {
                statement.close();
            }
            if (connection != null) {
                connection.close();
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
    public static void close(Statement statement, Connection connection) {
        /*
            DML的执行不产生ResultSet结果集，可以传入一个null;
            因此要先判断传入的对象是否为空，若非空则调用close方法关闭资源（动态绑定）
         */
        try {

            if (statement != null) {
                statement.close();
            }
            if (connection != null) {
                connection.close();
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) throws Exception {
        int id=3;

        String sql = "delete from tb_brand where id=?";
        PreparedStatement pstmt = conn.prepareStatement(sql);
        //执行
        pstmt.setInt(1,id);
        int count = pstmt.executeUpdate();//影响到的行数

        System.out.println(count>0);
        close(pstmt,conn);
    }
}
