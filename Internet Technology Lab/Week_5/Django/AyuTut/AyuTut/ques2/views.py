from django.shortcuts import render

# Create your views here.
def index_view(request, a, b):

    return render(request,'ques2/index.html',{'content':f'this is q2 {a} {b}'})
