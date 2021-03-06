<center><h2><b><font color=green>SQL必知必会第4版</font></b></h2></center>


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
* 函数
    * 文本函数
    

        <style>
        thead {color:green}
        tbody {color:gray;height:50px,}
        table th:first-of-type { width: 300px;}
        </style>
        <table>
            <thead>
            <tr>
                <th><font size="2"><center>函 数</center></th>
                <th><font size="2">说 明</th>
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
            <tr>
            <td></td>
            <td></td>
            </tr>
        </table>

    * 数值处理函数
        |函 数|说 明|
        |:---:|:---:|
        |ABS()|返回一个数的绝对值|
        |COS()|返回一个角度的余弦|
        |EXP()|返回一个数的指数值|
        |PI()|返回圆周率|
        |SIN()|返回一个角度的正弦|
        |SQRT()|返回一个数的平方根|
        |TAN()|返回一个角度的正切|


* 聚焦函数
    |函 数|说 明|
    |:----:|:-----:|
    |AVG()|返回某列的平均值|
    |COUNT()|返回某列的行数|
    |MAX()|返回某列的最大值|
    |MIN()|返回某列的最小值|
    |SUM()|返回某列值之和 |

    * AVG()
        ```SQL
        SELECT AVG(prod_price) AS avg_price FROM Products;

        /*AVG()也可以用来确定特定列或行的平均值。下面的例子返回特定供应商所提供产品的平均价格*/

        /*AVG()函数忽略列值为NULL的行*/
        
        ```
    * COUNT()
        ```SQL
        /*使用COUNT(*)对表中行的数目进行计数，不管表列中包含的是空值（NULL）还是非空值。使用COUNT(column)对特定列中具有值的行进行计数，忽略NULL值。*/

        /*一共行数*/
        SELECT COUNT(*) FROM table_name;

        /*选中的某个列的函数，不包括域为NULL的*/
        SELECT COUNT(column1_name) FROM table_name;


        ```
    * MAX()
        ```SQL
        /*MAX()返回指定列中的最大值*/
        SELECT MAX(column_name) FROM table_name;
        ```
    * MIN()
        ```SQL
        /*回指定列的最小值*/
        SELECT MAX(column_name) FROM table_name;
        ```
    * SUM()
        ```SQL
        /*返回指定列值的和（总计）,忽略列值为NULL的行*/
        SELECT SUM(column1_name*column2_name) AS column3_name FROM OrderItems WHERE column4_name = 20005;
        ```

* 聚集不同值
    * 对所有行执行计算，指定ALL参数或不指定参数
    * 只包含不同的值，指定DISTINCT参数。
        ```SQL
        /*使用了DISTINCT参数，平均值只考虑各个不同的价格*/
        /*同个key只考虑不同的值 2 3 3 AVG()=(2+3)/2*/
        SELECT DISTINCT AVG(column1_name) AS AVG_column FROM table_name WHERE column2_name="key";
        
        /*检索列中不同值的行数*/
        SELECT COUNT(DISTINCT column1_name) FROM table_name WHERE column2_name="key";

        ```
* 组合聚集函数
    ```SQL
    /*SELECT语句可根据需要包含多个聚集函数*/
    SELECT COUNT(*) AS num_items
    MIN(column1_name) AS column1_min
    MAX(column2_name) AS column2_max
    AVG(column3_name) AS column3_avg
    FROM table_name;
    ```
* 分组数据
    * GROUP BY 数据分组
        ```SQL
        /*按column2_name对column1_name进行分组*/
        SELECT column1_name FROM tablename GROUP BY column2_name;
        /*分组*/
        SELECT column1_name COUNT(*) FROM tablename GROUP BY column2_name;

        /*聚合函数通过作用于一组数据而只返回一个单个值，因此，在SELECT语句中出现的元素要么为一个聚合函数的输入值，要么为GROUP BY语句的参数*/
        SELECT id, COUNT(course) as numcourse, score FROM student GROUP BY id
        /*出现以上错误的原因是因为一个学生id对应多个分数，如果我们简单的在SELECT语句中写上score，则无法判断应该输出哪一个分数*/
        ```
    * HAVING 过滤分组
        ```SQL
        /*HAVING支持所有WHERE操作符,区别在于
        WHERE在数据分组前进行过滤，HAVING在数据分组后进行过滤*/

        SELECT id,AVG(score) AS avg_sc FROM student GROUP BY id HAVING AVG(score)>80;

        /*sql语句的执行过程是：
        select--> from-->where-->聚合函数(sum,min,max,avg,count)-->group by -->having --> order by -->*/

        select sum(score) from student  where sex='man' group by name having sum(score)>210

        /*HAVING子句会在分组之后对分组形成的结果进行过滤。这个过程需要聚合、排序，因此如果通过WHERE子句限制记录而省略HAVING子句，是可以提升性能的*/

        --使用HAVING
        SELECT deptno, SUM(sal) FROM emp GROUP BY deptno HAVING deptno = 20;
        
        --使用WHERE替换HAVING, 看到执行的操作少了一步
        SELECT deptno, SUM(sal) FROM emp WHERE deptno = 20 GROUP BY deptno;
        ```
    * 分组与排序
        |ORDERBY|GROUP BY|
        |:-:|:-:|
        |对产生的输出排序| 对行分组，但输出可能不是分组的顺序|
        |任意列都可以使用（甚至非选择的列也可以使用）| 只可能使用选择列或表达式列，而且必须使用每个选择列表达式|
        |不一定需要 |如果与聚集函数一起使用列（或表达式），则必须使用|
        ```SQL
        /*一般在使用GROUP BY子句时，应该也给出ORDER BY 子句,这是保证数据正确排序的唯一方法*/
        SELECT order_num ,COUNT(*) AS items FROM Products GROUP BY order_num HAVING COUNT(*)>=3 ORDER BY items,order_num;

        ```
    * SELECT 子句顺序
        |子 句|说 明|是否必须使用|
        |:-:|:-:|:-:|
        |SELECT| 要返回的列或表达式 |是|
        |FROM |从中检索数据的表| 仅在从表选择数据时使用|
        |WHERE |行级过滤 |否|
        |GROUP BY |分组说明 |仅在按组计算聚集时使用|
        |HAVING |组级过滤| 否|
        |ORDER BY| 输出排序顺序| 否|



</font>

