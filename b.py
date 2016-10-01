import json
import requests
from github import Github

access_token='0231643decfea4f7c1d16fdcf893dc6b85592da9'

url="https://api.github.com/user/repos?access_token=0231643decfea4f7c1d16fdcf893dc6b85592da9"
response=requests.get(url)

print json.dumps(response.json()[0], indent=1)
