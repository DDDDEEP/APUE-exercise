## 6.1 如何通过阴影文件取得加密口令？

## 6.2 若有超级用户权限，重新考虑上一题

## 6.3 编写程序，调用 uname 并输出 utsname 结构所有字段

## 6.4 计算可由 time_t 数据类型标识的最近时间，如果超出了这一时间则会如何？

`time_t` 为 `long int` 类型，包含一位符号位

假设为 32 位机器，则 1970:00:00:00 + 2^31 / 365 / 24 / 60 / 60 约为 2038 年

若超过最大时间后，时间大致回到 1901 年

## 6.5 编写程序，获取当前时间，并使用 strftime 将输出结果转换为类似 date 命令的默认输出；将 TZ 设置为不同的值，观察输出结果

