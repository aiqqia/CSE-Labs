from django.shortcuts import render
from django.http import HttpResponseRedirect
from .forms import FirstForm

# Create your views here.
def index_view(request):
    ff = FirstForm(request.POST or None)
    if request.method == 'POST':
        if ff.is_valid():
            context = { 'name' : ff.cleaned_data['name'],
                       'roll': ff.cleaned_data['roll'],
                       'subject':ff.cleaned_data['subject']}
            context['roll'] = int(context['roll'])
            request.session['context'] = context
            return HttpResponseRedirect("second/")
    return render(request, "ques2/first.html", {'ff':ff})

def second_view(request):
    if request.session.has_key('context'):
        context = request.session['context']
        return render(request, 'ques2/second.html', context)