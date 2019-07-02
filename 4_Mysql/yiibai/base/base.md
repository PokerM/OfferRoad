# 查询数据
```sql
SELECT 
    column1, column2,...
FROM 
    table_1
[INNER | LEFT | RIGHT] JOIN table_2 ON conditions
WHERE 
    conditions
GROUP BY column1
HAVING group_conditions
ORDER BY column_1
LIMIT offset, length;
```
- JOIN:根据某些连接条件从其他表中获取数据
- GROUP BY：将一组合成小分组，每个小分组应用聚合函数
- HAVING过滤器给予GROUP BY子句定义的小分组

WHERE子句：
- BETWEEN：给定范围内的值
- LIKE：基于模式匹配的值,%匹配0个或者多个字符，_匹配单个字符
- IN：指定值是否为匹配列表中的任何值
- IS NULL：判断是否NULL
```sql
select * from employees where officeCode between 1 3;
select * from employees where firstName like 'Le%';
select * from employees where firstName like 'T_m';
select * from employees where firstName NOT like 'T_m';
select * from offices where country in ('USA','France');
select * from offices where country NOT in ('USA','France');
select * from offices where state is NULL;
select * from offices where state is not NULL;
```

# 插入数据
```sql
INSERT INTO table(column1, column2, ...)
VALUES(value1, value2,...)
```
insert配合select完成表复制
1. 创建新表：CREATE table_name LIKE source_table_name; 
2. 复制表:INSERT INTO table_name select * from source_table_name;

## insert与on duplicate key update
当插入的新行违反了主键或者UNIQUE约束，MYSQL会发生错误。insert可以配合on duplicate key update来对该行进行更新
（那为什么不直接update？）

# 更新表数据
UPDATE用来更改表中单个行，一组行或所有行的列值。
```sql
UPDATE [LOW_PRIORITY] [IGNORE] table_name
SET
    column_name1 = expr1
    column_name2 = expr2
    ...
WHERE
    condition;
```
- LOW_PRIORITY:在表级锁的存储引擎生效，当表被读取时，update被延迟，直到没有读取数据连接
- IGNORE：忽略错误

# 删除表数据
```sql
DELETE FROM table_name WHERE condition;
```
## DELETE CASCADE
加入存在两张表，一张为建筑物(buildings)，另一张为房间(rooms)。每一个建筑物有一个或多个房间，而每一个房间属于一个建筑物，当建筑物不存在时，房间也不会存在。

1. 创建buildings表
2. 创建room表
3. 插入数据
4. 查询buildings数据
5. 删除部分buildings
6. 查询buildings数据
## DELETE JOIN

