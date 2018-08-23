<center><h2><b><font color=green>SQL必知必会第4版📖</font></b></h2></center>


 &nbsp; [![SQL][sql-img]][sql] [![Oracle][oracle-img]][oracle]  [![Chat 857205436@qq.com][chat-img]][chat]

 [sql]:https://www.mysql.com
 [sql-img]:https://img.shields.io/badge/MySQL-Web-orange.svg

 [oracle]:https://www.oracle.com/index.html
 [oracle-img]:https://img.shields.io/badge/ORACLE-Net-red.svg

 [chat]:https://blog.csdn.net/qq_30366449
 [chat-img]:https://img.shields.io/badge/Chat-Git-black.svg


 <p>
 <center>
 
<!--
整段不可见内容
<div align=center><img src="https://labs.mysql.com/common/logos/mysql-logo.svg?v2">
-->

![MySQL](https://labs.mysql.com/common/logos/mysql-logo.svg?v2 "MySQL")

[//]: # (This may be the most platform independent comment)
   
 </center>
 </p>

 |column1_name|column2_name|column3_name|
 |:----------:|:----------:|:----------:|
 |content1    |content2    |content3    |
 |=========|===============|============|


 <font size=3 color=#ffff41>

 * SHOW  显示/查看数据库
     ```SQL
     show DATABASES;
     ```

 * CREATE 创建数据库
     ```SQL
     CREATE DATABASE dbname;
     ```
 * DROP 删除数据库
     ```SQL
     DROP DATABASE dbname;
     ```
 * USE 使用数据库
     ```SQL
     USE dbname;
     ```

 * SELECT 选择

     ```SQL<center><h2><b><font color=green>SQL必知必会第4版</font></b></h2></center>
 <center><h2><b><font color=green>SQL必知必会第4版</font></b></h2></center>

 # 
 &nbsp; [![SQL][sql-img]][sql] [![Oracle][oracle-img]][oracle]  [![Chat 857205436@qq.com][chat-img]][chat]

 [sql]:https://www.mysql.com
 [sql-img]:https://img.shields.io/badge/MySQL-Web-orange.svg

 [oracle]:https://www.oracle.com/index.html
 [oracle-img]:https://img.shields.io/badge/ORACLE-Net-red.svg

 [chat]:https://blog.csdn.net/qq_30366449
 [chat-img]:https://img.shields.io/badge/Chat-Git-black.svg


 <p>
 <center>

 ![MySQL](https://labs.mysql.com/common/logos/mysql-logo.svg?v2 "MySQL")


 </center>
 </p>

 <font size=3 color=#ffff41>

 * SHOW  显示/查看数据库
     ```SQL
     SHOW DATABASES;
     ```

 * CREATE 创建数据库
     ```SQL
     CREATE DATABASE dbname;
     ```
 * DROP 删除数据库
     ```SQL
     DROP DATABASE dbname;
     ```
 * USE 使用数据库
     ```SQL
     USE dbname;
     ```

 * SELECT 选择

     ```SQL
     /*默认升序ASC*/
     SELECT column_name FROM table_name;
     SELECT DISTINCT column_name FROM table_name;/*返回不同值*/
     SELECT column_name FROM table_name LIMIT 5;
     SELECT column_name FROM table_name LIMIT 5 OFFSET 3;
     SELECT column_name FROM table_name LIMIT 5,3;

     /*SELECT语句为测试、检验函数和计算提供了很好的方法。虽然SELECT通常用于从表中检索数据，但是省略了FROM子句后就是简单地访问和处理表达式，例如SELECT 3*2;将返回6，SELECT TRIM(' abc ');将返回abc，SELECT Now();使用Now()函数返回当前日期和时间*/
     ```

 * ORDER BY 排序
     ```SQL
     SELECT column1_name column2_name column3_name
     FROM table_name
     ORDER BY column2_name

     ```
   
 * DESC 选择降序
   ```SQL
     SELECT column_name FROM table_name DESC;
     /*DESC仅应用到直接位于其前面的列名*/
     SELECT column1_name column2_name
     FROM table_name
     ORDER BY column1_name column2_name DESC;
     /*仅仅对column2_name列降序，其他列默认升序*/
     ```

 * WHERE 过滤选择
     * BETWEEN *** AND ***
     * IS NULL
     ```SQL
     /*通过过滤选择不包含指定值的所有行时，你可能希望返回含NULL值的行。但是这做不到。因为未知（unknown）有特殊的含义，数据库不知道它们是否匹配，所以在进行匹配过滤或非匹配过滤时，不会返回这些结果。*/
     SELECT column1_name FROM table_name WHERE column2_name<>2 ORDER BY column1_name;
     ```

 * AND OR 且 或
     
     ```SQL
     AND 运算优先级比 OR 高
     SELECT column1_name FROM tablename WHERE column1_name>1 AND column2_name <10 OR column3_name="liu"
     ```

 * IN 包含
     ```SQL
     /*WHERE子句中用来指定要匹配值的清单的关键字，功能与OR相当*/
     SELECT column1_name FROM tablename WHERE column2_name IN("key1","key2",...,"keyn") ORDER BY column3_name;
     /*括号里面全部都有，也就类似于OR*/
     ```
 * NOT 否定
     ```SQL
     SELECT column1_name FROM tablename WHERE NOT column2_name="key";
     ```

 * 通配符 LIKE 操作符
     * % 百分号
     
         ```SQL
         /*检索LIU开头的任意字符*/
         SELECT column1_name FROM tablename WHERE column2_name LIKE "LIU%"
         
         /*检索含有LIU的任意字符*/
         SELECT column1_name FROM tablename WHERE column2_name LIKE "%LIU%"

         /*根据邮件地址的一部分来查找电子邮件,把通配符放在搜索模式中间是很有用的，例如:*/
         WHERE email LIKEb%@liu.com。

         /*包括Access在内的许多DBMS都用空格来填补字段的内容。例如，如果某列有50个字符，而存储的文本为Fish bean bag toy(17个字符),则为填满该列需要在文本后附加33个空格。这样做一般对数据及其使用没有影响，但是可能对上述SQL语句有负面影响。子句 WHERE prod_name LIKE 'F%y'只匹配以F开头、以y结尾的prod_name。如果值后面跟空格，则不是以y结尾，所以Fish bean bag toy就不会检索出来。简单的解决办法是给搜索模式再增加一个%号：'F%y%'还匹配y之后的字符（或空格）。*/
         ```
     * _ 下划线
         ```SQL
         /*下划线的用途与%一样，但它只匹配单个字符，而不是多个字符。*/

         /*检索第二三个为IU的key*/
         SELECT column1_name,column2_name FROM tablename WHERE column1_name LIKE "_IU%";

         ```
     * [] 方括号
         ```SQL
         /*指定一个字符集，它必须匹配指定位置（通配符的位置）的一个字符。SELECT cust_contact FROM Customers WHERE cust_contact LIKE '[^JM]%'ORDER BY cust_contact;*/
         SELECT cust_contact FROM Customers WHERE cust_contact LIKE '[J]%';

         ```

 * 计算字段
     * 拼接(concatenate)
         ```SQL
         /*Access和SQL Server使用+号。DB2、Oracle、PostgreSQL、SQLite和Open Office Base使用||*/
         SELECT vend_name + ' (' + vend_country + ')' FROM Vendors ORDER BY vend_name;

         /*MySQL中用CONCAT函数*/
         SELECT CONCAT(vend_name,'(',vend_country,')') FROM Vendors ORDER BY vend_name;

         /*函数CONCAT(string1,string2,…)   说明 : string1,string2代表字符串,concat函数在连接字符串的时候，只要其中一个是NULL,那么将返回NULL*/
         ```
     * AS 别名
         ```SQL
         SELECT CONCAT(column1_name,column2_name) AS columnnew_name FROM table name;
         ```
     * 算术计算 +-*/
         ```SQL
         SELECT column1_name,column2_name,column3_name*column4_name AS columnnew_name FROM tablename WHERE column1_name<10;
         ```
 </font>


 # 
 &nbsp; [![SQL][sql-img]][sql] [![Oracle][oracle-img]][oracle]  [![Chat 857205436@qq.com][chat-img]][chat]

 [sql]:https://www.mysql.com
 [sql-img]:https://img.shields.io/badge/MySQL-Web-orange.svg

 [oracle]:https://www.oracle.com/index.html
 [oracle-img]:https://img.shields.io/badge/ORACLE-Net-red.svg

 [chat]:https://blog.csdn.net/qq_30366449
 [chat-img]:https://img.shields.io/badge/Chat-Git-black.svg


 <p>
 <center>

 ![MySQL](https://labs.mysql.com/common/logos/mysql-logo.svg?v2 "MySQL")


 </center>
 </p>

 <font size=3 color=#ffff41>

 * SHOW  显示/查看数据库
     ```SQL
     SHOW DATABASES;
     ```

 * CREATE 创建数据库
     ```SQL
     CREATE DATABASE dbname;
     ```
 * DROP 删除数据库
     ```SQL
     DROP DATABASE dbname;
     ```
 * USE 使用数据库
     ```SQL
     USE dbname;
     ```

 * SELECT 选择

     ```SQL
     /*默认升序ASC*/
     SELECT column_name FROM table_name;
     SELECT DISTINCT column_name FROM table_name;/*返回不同值*/
     SELECT column_name FROM table_name LIMIT 5;
     SELECT column_name FROM table_name LIMIT 5 OFFSET 3;
     SELECT column_name FROM table_name LIMIT 5,3;

     /*SELECT语句为测试、检验函数和计算提供了很好的方法。虽然SELECT通常用于从表中检索数据，但是省略了FROM子句后就是简单地访问和处理表达式，例如SELECT 3*2;将返回6，SELECT TRIM(' abc ');将返回abc，SELECT Now();使用Now()函数返回当前日期和时间*/
     ```

 * ORDER BY 排序
     ```SQL
     SELECT column1_name column2_name column3_name
     FROM table_name
     ORDER BY column2_name

     ```
   
 * DESC 选择降序
   ```SQL
     SELECT column_name FROM table_name DESC;
     /*DESC仅应用到直接位于其前面的列名*/
     SELECT column1_name column2_name
     FROM table_name
     ORDER BY column1_name column2_name DESC;
     /*仅仅对column2_name列降序，其他列默认升序*/
     ```

 * WHERE 过滤选择
     * BETWEEN *** AND ***
     * IS NULL
     ```SQL
     /*通过过滤选择不包含指定值的所有行时，你可能希望返回含NULL值的行。但是这做不到。因为未知（unknown）有特殊的含义，数据库不知道它们是否匹配，所以在进行匹配过滤或非匹配过滤时，不会返回这些结果。*/
     SELECT column1_name FROM table_name WHERE column2_name<>2 ORDER BY column1_name;
     ```

 * AND OR 且 或
     
     ```SQL
     AND 运算优先级比 OR 高
     SELECT column1_name FROM tablename WHERE column1_name>1 AND column2_name <10 OR column3_name="liu"
     ```

 * IN 包含
     ```SQL
     /*WHERE子句中用来指定要匹配值的清单的关键字，功能与OR相当*/
     SELECT column1_name FROM tablename WHERE column2_name IN("key1","key2",...,"keyn") ORDER BY column3_name;
     /*括号里面全部都有，也就类似于OR*/
     ```
 * NOT 否定
     ```SQL
     SELECT column1_name FROM tablename WHERE NOT column2_name="key";
     ```

 * 通配符 LIKE 操作符
     * % 百分号
     
         ```SQL
         /*检索LIU开头的任意字符*/
         SELECT column1_name FROM tablename WHERE column2_name LIKE "LIU%"
         
         /*检索含有LIU的任意字符*/
         SELECT column1_name FROM tablename WHERE column2_name LIKE "%LIU%"

         /*根据邮件地址的一部分来查找电子邮件,把通配符放在搜索模式中间是很有用的，例如:*/
         WHERE email LIKEb%@liu.com。

         /*包括Access在内的许多DBMS都用空格来填补字段的内容。例如，如果某列有50个字符，而存储的文本为Fish bean bag toy(17个字符),则为填满该列需要在文本后附加33个空格。这样做一般对数据及其使用没有影响，但是可能对上述SQL语句有负面影响。子句 WHERE prod_name LIKE 'F%y'只匹配以F开头、以y结尾的prod_name。如果值后面跟空格，则不是以y结尾，所以Fish bean bag toy就不会检索出来。简单的解决办法是给搜索模式再增加一个%号：'F%y%'还匹配y之后的字符（或空格）。*/
         ```
     * _ 下划线
         ```SQL
         /*下划线的用途与%一样，但它只匹配单个字符，而不是多个字符。*/

         /*检索第二三个为IU的key*/
         SELECT column1_name,column2_name FROM tablename WHERE column1_name LIKE "_IU%";

         ```
     * [] 方括号
         ```SQL
         /*指定一个字符集，它必须匹配指定位置（通配符的位置）的一个字符。SELECT cust_contact FROM Customers WHERE cust_contact LIKE '[^JM]%'ORDER BY cust_contact;*/
         SELECT cust_contact FROM Customers WHERE cust_contact LIKE '[J]%';

         ```

 * 计算字段
     * 拼接(concatenate)
         ```SQL
         /*Access和SQL Server使用+号。DB2、Oracle、PostgreSQL、SQLite和Open Office Base使用||*/
         SELECT vend_name + ' (' + vend_country + ')' FROM Vendors ORDER BY vend_name;

         /*MySQL中用CONCAT函数*/
         SELECT CONCAT(vend_name,'(',vend_country,')') FROM Vendors ORDER BY vend_name;

         /*函数CONCAT(string1,string2,…)   说明 : string1,string2代表字符串,concat函数在连接字符串的时候，只要其中一个是NULL,那么将返回NULL*/
         ```
     * AS 别名
         ```SQL
         SELECT CONCAT(column1_name,column2_name) AS columnnew_name FROM table name;
         ```
     * 算术计算 +-*/
         ```SQL
         SELECT column1_name,column2_name,column3_name*column4_name AS columnnew_name FROM tablename WHERE column1_name<10;
         ```
 </font>


     /*默认升序ASC*/
     SELECT column_name FROM table_name;
     SELECT DISTINCT column_name FROM table_name;/*返回不同值*/
     SELECT column_name FROM table_name LIMIT 5;
     SELECT column_name FROM table_name LIMIT 5 OFFSET 3;
     SELECT column_name FROM table_name LIMIT 5,3;

     /*SELECT语句为测试、检验函数和计算提供了很好的方法。虽然SELECT通常用于从表中检索数据，但是省略了FROM子句后就是简单地访问和处理表达式，例如SELECT 3*2;将返回6，SELECT TRIM(' abc ');将返回abc，SELECT Now();使用Now()函数返回当前日期和时间*/
     ```

 * ORDER BY 排序
     ```SQL
     SELECT column1_name column2_name column3_name
     FROM table_name
     ORDER BY column2_name

     ```
   
 * DESC 选择降序
   ```SQL
     SELECT column_name FROM table_name DESC;
     /*DESC仅应用到直接位于其前面的列名*/
     SELECT column1_name column2_name
     FROM table_name
     ORDER BY column1_name column2_name DESC;
     /*仅仅对column2_name列降序，其他列默认升序*/
     ```

 * WHERE 过滤选择
     * BETWEEN *** AND ***
     * IS NULL
     ```SQL
     /*通过过滤选择不包含指定值的所有行时，你可能希望返回含NULL值的行。但是这做不到。因为未知（unknown）有特殊的含义，数据库不知道它们是否匹配，所以在进行匹配过滤或非匹配过滤时，不会返回这些结果。*/
     SELECT column1_name FROM table_name WHERE column2_name<>2 ORDER BY column1_name;
     ```

 * AND OR 且 或
     
     ```SQL
     AND 运算优先级比 OR 高
     SELECT column1_name FROM tablename WHERE column1_name>1 AND column2_name <10 OR column3_name="liu"
     ```

 * IN 包含
     ```SQL
     /*WHERE子句中用来指定要匹配值的清单的关键字，功能与OR相当*/
     SELECT column1_name FROM tablename WHERE column2_name IN("key1","key2",...,"keyn") ORDER BY column3_name;
     /*括号里面全部都有，也就类似于OR*/
     ```
 * NOT 否定
     ```SQL
     SELECT column1_name FROM tablename WHERE NOT column2_name="key";
     ```

 * 通配符 LIKE 操作符
     * % 百分号
     
         ```SQL
         /*检索LIU开头的任意字符*/
         SELECT column1_name FROM tablename WHERE column2_name LIKE "LIU%"
         
         /*检索含有LIU的任意字符*/
         SELECT column1_name FROM tablename WHERE column2_name LIKE "%LIU%"

         /*根据邮件地址的一部分来查找电子邮件,把通配符放在搜索模式中间是很有用的，例如:*/
         WHERE email LIKEb%@liu.com。

         /*包括Access在内的许多DBMS都用空格来填补字段的内容。例如，如果某列有50个字符，而存储的文本为Fish bean bag toy(17个字符),则为填满该列需要在文本后附加33个空格。这样做一般对数据及其使用没有影响，但是可能对上述SQL语句有负面影响。子句 WHERE prod_name LIKE 'F%y'只匹配以F开头、以y结尾的prod_name。如果值后面跟空格，则不是以y结尾，所以Fish bean bag toy就不会检索出来。简单的解决办法是给搜索模式再增加一个%号：'F%y%'还匹配y之后的字符（或空格）。*/
         ```
     * _ 下划线
         ```SQL
         /*下划线的用途与%一样，但它只匹配单个字符，而不是多个字符。*/

         /*检索第二三个为IU的key*/
         SELECT column1_name,column2_name FROM tablename WHERE column1_name LIKE "_IU%";

         ```
     * [] 方括号
         ```SQL
         /*指定一个字符集，它必须匹配指定位置（通配符的位置）的一个字符。SELECT cust_contact FROM Customers WHERE cust_contact LIKE '[^JM]%'ORDER BY cust_contact;*/
         SELECT cust_contact FROM Customers WHERE cust_contact LIKE '[J]%';

         ```

 * 计算字段
     * 拼接(concatenate)
         ```SQL
         /*Access和SQL Server使用+号。DB2、Oracle、PostgreSQL、SQLite和Open Office Base使用||*/
         SELECT vend_name + ' (' + vend_country + ')' FROM Vendors ORDER BY vend_name;

         /*MySQL中用CONCAT函数*/
         SELECT CONCAT(vend_name,'(',vend_country,')') FROM Vendors ORDER BY vend_name;

         /*函数CONCAT(string1,string2,…)   说明 : string1,string2代表字符串,concat函数在连接字符串的时候，只要其中一个是NULL,那么将返回NULL*/
         ```
     * AS 别名
         ```SQL

         ```
     * 算术计算 +-*/
         ```SQL
         SELECT column1_name,column2_name,column3_name*column4_name AS columnnew_name FROM tablename WHERE column1_name<10;
         ```
         
 * 函数
     <table>
         <thead>
         <tr>
             <th><font size="2"><center>函数</center></th>
             <th><font size="2">说明</th>
         </tr>
         <tbody>
         <tr>
             <td><font size="2">LEFT()(或使用子字符串函数)</font></td>
             <td><font size="2">返回字符串左边的字符</font></td>
         </tr>
             <td><font size="2">LENGTH()(也使用DATALENGTH()或LEN()</font></td>
             <td><font size="2">返回字符串的长度</font></td>
         <tr>
         <td><font size="2">LOWER()(Access使用LCASE())</font></td>
         <td><font size="2">将字符串转换为小写</font></td>
         </tr>
         <tr>
         <td><font size="2">LTRIM()</font></td>
         <td><font size="2">去掉字符串左边的空格</font></td>
         </tr>
         <tr>
         <td><font size="2">RIGHT()(或使用子字符串函数)</font></td>
         <td><font size="2">返回字符串右边的字符</font></td>
         </tr>
         <tr>
         <td><font size="2">RTRIM()</font></td>
         <td><font size="2">去掉字符串右边的空格</font></td>
         </tr>
         <tr>
         <td><font size="2">SOUNDEX()</font></td>
         <td><font size="2">返回字符串的SOUNDEX值</font></td>
         </tr>
         <tr>
         <td><font size="2">UPPER()(Access使用UCASE())</font></td>
         <td><font size="2">将字符串转换为大写</font></td>
             </tr>

 </table>



 </font>
