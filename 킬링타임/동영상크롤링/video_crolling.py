import urllib.request

def save_video(video_url) :
    savename = 'save_by_urllib.mp4'
    urllib.request.urlretrieve(video_url,savename)
    print("저장완료")


url = 'https://www.youtube.com/watch?v=LGzhC9prUPw'
save_video(url)