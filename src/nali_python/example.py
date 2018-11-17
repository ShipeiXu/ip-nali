#!/usr/local/bin/python3

import ipdb,sys

def test_free():
    db = ipdb.City("./mydata4vipweek2.ipdb")
    print(db.is_ipv4(), db.is_ipv6())
    print(db.languages())
    print(db.fields())
    print(db.build_time())
    print(db.find("1.1.1.1", "CN"))
    print(db.find("118.28.1.1", "CN"))

    try:
        print(db.find("2000:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF", "CN"))
    except Exception as e:
        print(e)


def test_city_ipv4():
    db = ipdb.City("./mydata4vipweek2.ipdb")
    print(db.is_ipv4(), db.is_ipv6())
    print(db.languages())
    print(db.fields())
    print(db.build_time())
    print(db.find("1.1.1.1", "CN"))
    print(db.find_map("8.8.8.8", "CN"))
    print(db.find_info("8.8.8.8", "CN").country_name)
    print(db.find_info("8.8.8.8", "CN").region_name)
    print(db.find_info("8.8.8.8", "CN").city_name)
    print(db.find_info("8.8.8.8", "CN").owner_name)
    print(db.find_info("8.8.8.8", "CN").isp_domain)


def test_city_ipv6():
    db = ipdb.City("./mydata4vipweek2.ipdb")
    print(db.is_ipv4(), db.is_ipv6())
    print(db.languages())
    print(db.fields())
    print(db.build_time())
    print(db.find("2001:250:200::", "CN"))

    try:
        print(db.find("2000:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF", "CN"))
    except Exception as e:
        print(e)


def test_district():
    db = ipdb.District("c:/work/ipdb/china_district.ipdb")
    print(db.is_ipv4(), db.is_ipv6())
    print(db.languages())
    print(db.fields())
    print(db.build_time())
    print(db.find("1.12.13.255", "CN"))
    print(db.find_map("1.12.13.255", "CN"))
    print(db.find_info("1.12.13.255", "CN").country_name)


def test_base_station():
    db = ipdb.BaseStation("./mydata4vipweek2.ipdb")
    print(db.is_ipv4(), db.is_ipv6())
    print(db.languages())
    print(db.fields())
    print(db.build_time())
    print(db.find_map("117.136.83.55", "CN"))


def test_idc_list():
    db = ipdb.IDC("./mydata4vipweek2.ipdb")
    print(db.find_map("1.1.1.1", "CN"))
    print(db.find_map("8.8.8.8", "CN"))

test_free()
#test_city_ipv4()
#test_base_station()
#test_idc_list()
#test_city_ipv4()
