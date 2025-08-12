# Write your MySQL query statement below
select v.customer_id,count(*) as count_no_trans from Visits v left join Transactions using(visit_id) where transaction_id is null group by v.customer_id;