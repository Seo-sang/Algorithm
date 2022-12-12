import requests


BASE_URL = "https://68ecj67379.execute-api.ap-northeast-2.amazonaws.com/api"

def method(method : str, url : str, data={}, token = "", init=False):
    headers={}
    headers['Content-Type'] = "application/json"
    if init is True:
        headers['X-Auth-Token'] = token
    else:
        headers['Authorization'] = token

    if method == "GET":
        response = requests.get(BASE_URL + url, headers=headers)
    elif method == "PUT":
        response = requests.put(BASE_URL + url, headers=headers, json=data)
    elif method == "POST":
        response = requests.post(BASE_URL + url, headers=headers, json=data)
    else:
        return {}

    if response.status_code == 200:
        return response.json()
    else:
        return {}