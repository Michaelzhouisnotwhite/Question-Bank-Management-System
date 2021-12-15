import json


def get_sql_config():
    config = json.load(open("./config.json"))
    user_name = config["User Name"]
    password = config["Password"]
    host = config["Host"]
    db_name = config["DataBase Name"]

    warp = "\n"
    output = user_name + warp + password + warp + host + warp + db_name
    
    f = open("config_output", "w")
    f.write(output)
    f.close()
    
    
    
if __name__ == "__main__":
    get_sql_config()
