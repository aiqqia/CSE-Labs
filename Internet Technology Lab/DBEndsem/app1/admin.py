from django.contrib import admin
from . import models

# Register your models here.
class ProductAdmin(admin.ModelAdmin):
    list_display = ('title','body','price','timestamp','id',)

admin.site.register(models.Product, ProductAdmin)

class OptionAdmin(admin.ModelAdmin):
    list_display = ('id', 'value', 'number',)

admin.site.register(models.Option, OptionAdmin)

class QuestionAdmin(admin.ModelAdmin):
    list_display = ('id', 'question',)

admin.site.register(models.Question, QuestionAdmin)