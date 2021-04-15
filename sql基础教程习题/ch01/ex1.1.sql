create database sqlex;
use database sqlex;
create table Addressbook(
    -> regist_no INTEGER NOT NULL,
    -> name varchar(128) not null,
    -> address varchar(256) not null,
    -> tel_no char(10),
    -> mail_address char(20),
    -> primary key(regist_no));

-- 确认结果 show columns from Addressbook;