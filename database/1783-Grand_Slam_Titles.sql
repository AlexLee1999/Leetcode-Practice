Select Players.player_id, Players.player_name, count(list.won) as 'grand_slams_count'
From Players
Join (
    Select year, 'Wimbledon' as game, Wimbledon as won
    From Championships
    Union 
    Select year, 'Fr_open' as game, Fr_open as won
    From Championships
    Union
    Select year, 'US_open' as game, US_open as won
    From Championships
    Union
    Select year, 'Au_open' as game, Au_open as won
    From Championships
) list
on list.won = Players.player_id
Group by Players.player_id;