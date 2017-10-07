#更新订单最终状态
insert into orderreqfinalstatus
(select a.investor_id, a.ordinal, b.order_local_id, b.order_status, a.trading_day from 
(select investor_id, ordinal, trading_day from orderreq) as a
LEFT JOIN
(select investor_id, order_local_id, order_status, trading_day from 
(select investor_id, order_local_id, order_status, trading_day from orders now
where not exists (select investor_id, order_local_id, trading_day from orders where investor_id = now.investor_id and order_local_id = now.order_local_id and trading_day = now.trading_day and id > now.id)) as orderfinalstatus
) as b
ON a.investor_id = b.investor_id AND (cast(a.ordinal as signed) + 1000000000) = cast(b.order_local_id as signed) AND a.trading_day = b.trading_day)

#更新用户信息表
insert into investor_info
    select a.investor_id, b.trading_volume, b.trading_amount, c.num_orderreq, d.order_failure, d.order_failure/c.num_orderreq, 
    e.order_cancel, e.order_cancel/(c.num_orderreq - d.order_failure), f.order_trading, f.order_trading/(c.num_orderreq - d.order_failure),
    g1.count, g2.count, g3.count, g4.count, g5.count, g6.count, g7.count, g8.count, g9.count, g10.count, g11.count, g12.count, g13.count, g14.count, g15.count, g16.count,
    a.trading_day from
        ((select investor_id, trading_day from orderreqfinalstatus group by trading_day, investor_id) as a
        LEFT JOIN
        (select investor_id, trading_day, sum(volume) as trading_volume, sum(trade_amount) as trading_amount from trade group by trading_day, investor_id) as b
        ON a.investor_id = b.investor_id AND a.trading_day = b.trading_day 
        LEFT JOIN
        (select investor_id, trading_day, count(*) as num_orderreq from orderReq group by trading_day, investor_id) as c
        ON a.investor_id = c.investor_id AND a.trading_day = c.trading_day 
        LEFT JOIN
        (select d1.investor_id, d1.trading_day, IFNULL(d1.count, 0)+IFNULL(d2.count, 0) as order_failure from
            (select investor_id, trading_day, count(*) as count from orderreqfinalstatus where ISNULL(order_local_id) GROUP BY trading_day, investor_id) as d1
            LEFT JOIN
            (select investor_id, trading_day, count(*) as count from orderreqfinalstatus where order_status = '7' GROUP BY trading_day, investor_id) as d2
            ON d1.investor_id = d2.investor_id AND d1.trading_day = d2.trading_day
        ) as d
        ON a.investor_id = d.investor_id AND a.trading_day = d.trading_day
        LEFT JOIN
        (select investor_id, trading_day, count(*) as order_cancel from orderreqfinalstatus where order_status = '5' or order_status = '6' GROUP BY trading_day, investor_id) as e 
        ON a.investor_id = e.investor_id AND a.trading_day = e.trading_day
        LEFT JOIN
        (select investor_id, trading_day, count(*) as order_trading from
            (select f1.investor_id, f1.trading_day, f1.ordinal, f2.order_local_id from orderreq f1, trade f2 
            where f1.investor_id = f2.investor_id and f1.trading_day = f2.trading_day and cast(f1.ordinal as unsigned) + 1000000000 = cast(f2.order_local_id as unsigned)) as f3
        GROUP BY trading_day, investor_id) as f
        ON a.investor_id = f.investor_id AND a.trading_day = f.trading_day
        LEFT JOIN
        (select investor_id, trading_day, count(*) as count from orderreq 
        where time >= 90000000 and time < 93000000
        group by trading_day, investor_id) as g1
        ON a.investor_id = g1.investor_id AND a.trading_day = g1.trading_day
        LEFT JOIN
        (select investor_id, trading_day, count(*) as count from orderreq 
        where time >= 93000000 and time < 100000000
        group by trading_day, investor_id) as g2 
        ON a.investor_id = g2.investor_id AND a.trading_day = g2.trading_day
		LEFT JOIN
        (select investor_id, trading_day, count(*) as count from orderreq 
        where time >= 100000000 and time < 103000000
        group by trading_day, investor_id) as g3 
        ON a.investor_id = g3.investor_id AND a.trading_day = g3.trading_day
        LEFT JOIN
        (select investor_id, trading_day, count(*) as count from orderreq 
        where time >= 103000000 and time < 110000000
        group by trading_day, investor_id) as g4
        ON a.investor_id = g4.investor_id AND a.trading_day = g4.trading_day
	    LEFT JOIN
        (select investor_id, trading_day, count(*) as count from orderreq 
        where time >= 110000000 and time < 113000000
        group by trading_day, investor_id) as g5
        ON a.investor_id = g5.investor_id AND a.trading_day = g5.trading_day
        LEFT JOIN
        (select investor_id, trading_day, count(*) as count from orderreq 
        where time >= 113000000 and time < 120000000
        group by trading_day, investor_id) as g6
        ON a.investor_id = g6.investor_id AND a.trading_day = g6.trading_day
        LEFT JOIN
        (select investor_id, trading_day, count(*) as count from orderreq 
        where time >= 120000000 and time < 123000000
        group by trading_day, investor_id) as g7
        ON a.investor_id = g7.investor_id AND a.trading_day = g7.trading_day
        LEFT JOIN
        (select investor_id, trading_day, count(*) as count from orderreq 
        where time >= 123000000 and time < 130000000
        group by trading_day, investor_id) as g8
        ON a.investor_id = g8.investor_id AND a.trading_day = g8.trading_day
        LEFT JOIN
        (select investor_id, trading_day, count(*) as count from orderreq 
        where time >= 130000000 and time < 133000000
        group by trading_day, investor_id) as g9
        ON a.investor_id = g9.investor_id AND a.trading_day = g9.trading_day
        LEFT JOIN
        (select investor_id, trading_day, count(*) as count from orderreq 
        where time >= 133000000 and time < 140000000
        group by trading_day, investor_id) as g10
        ON a.investor_id = g10.investor_id AND a.trading_day = g10.trading_day
        LEFT JOIN
        (select investor_id, trading_day, count(*) as count from orderreq 
        where time >= 140000000 and time < 143000000
        group by trading_day, investor_id) as g11
        ON a.investor_id = g11.investor_id AND a.trading_day = g11.trading_day
        LEFT JOIN
        (select investor_id, trading_day, count(*) as count from orderreq 
        where time >= 143000000 and time < 150000000
        group by trading_day, investor_id) as g12
        ON a.investor_id = g12.investor_id AND a.trading_day = g12.trading_day
        LEFT JOIN
        (select investor_id, trading_day, count(*) as count from orderreq 
        where time >= 150000000 and time < 153000000
        group by trading_day, investor_id) as g13
        ON a.investor_id = g13.investor_id AND a.trading_day = g13.trading_day
        LEFT JOIN
        (select investor_id, trading_day, count(*) as count from orderreq 
        where time >= 153000000 and time < 160000000
        group by trading_day, investor_id) as g14
        ON a.investor_id = g14.investor_id AND a.trading_day = g14.trading_day
        LEFT JOIN
        (select investor_id, trading_day, count(*) as count from orderreq 
        where time >= 160000000 and time < 163000000
        group by trading_day, investor_id) as g15
        ON a.investor_id = g15.investor_id AND a.trading_day = g15.trading_day
        LEFT JOIN
        (select investor_id, trading_day, count(*) as count from orderreq 
        where time >= 163000000 and time < 170000000
        group by trading_day, investor_id) as g16
        ON a.investor_id = g16.investor_id AND a.trading_day = g16.trading_day
        )
    GROUP BY trading_day, investor_id


#更新标的信息表
insert into instrument_info
    select instrument_id, sum(volume), sum(trade_amount), trading_day from trade group by trading_day, instrument_id












		