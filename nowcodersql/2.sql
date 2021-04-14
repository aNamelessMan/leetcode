select * from employees order by hire_date desc limit 2,1
/* 同上一题 */
/* 考虑可能有重复值的情况 */
select * from employees where hire_date = (select hire_date from employees order by hire_date desc limit 2,1)