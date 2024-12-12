# Write your MySQL query statement below
SELECT Address.city, Address.state, Person.firstName, Person.lastName 
FROM Address 
right JOIN Person 
ON Address.personId = Person.personId;
