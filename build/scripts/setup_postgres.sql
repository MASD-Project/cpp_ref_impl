--
-- Copyright (C) 2012-2016 Marco Craveiro <marco.craveiro@gmail.com>
--
-- This program is free software; you can redistribute it and/or modify
-- it under the terms of the GNU General Public License as published by
-- the Free Software Foundation; either version 3 of the License, or
-- (at your option) any later version.
--
-- This program is distributed in the hope that it will be  useful,
-- but WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
-- GNU General Public License for more details.
--
-- You should have received a copy of the GNU General Public License
-- along with this program; if not, write to the Free Software
-- Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
-- MA 02110-1301, USA.
--

-- Database for the unit tests
drop database if exists musseque;
create database musseque;

-- Role for the unit tests
drop role if exists build;
create role build login password 'build';

-- Assign database to role.
grant all privileges on database musseque to build;

-- Connect to new database and add schema for Northwind tests.
\c musseque
create schema "NORTHWIND";
grant all privileges on schema "NORTHWIND" to build;
