import sys,tweepy

def twitter_auth():
    try:
        consumer_key = 'POvE4o3DrCGqFnNSitn5p5jqp'
        consumer_secret= 'fK5ttittXX4m17nNRpDdpX2pYa1R1CiS4cBPcTJUJJlg7hmG5E'
        access_token= '1378427626331631620-ves4sYgxzb1Jxuah72k0YEO4V5BmaW'
        access_secret= '6ifjv3nvNTYCzzGg0UcJI0s5g1X0mMYFGU84SgD9fjxnF'
    except KeyError:
        sys.stderr.write("Twitter_ * enviroment variable not set \n")
        sys.exit(1)

    auth = tweepy.OAuthHandler(consumer_key,consumer_secret)
    auth.set_access_token(access_token, access_secret)
    return auth


def get_twitter_client():
    auth=twitter_auth()
    client = tweepy.API(auth, wait_on_reate_limit=True)
    return client

if __name__ == '__main__':
    user=input("Enter username: ")
    client = get_twitter_client()
    for status in tweepy.Cursor(client.home_timeline, screen_name=user).items(10):
    print(status.text)