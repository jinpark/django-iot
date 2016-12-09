from django.db import models

class ButtonPress(models.Model):
    direction = models.CharField(max_length=30)
    time = models.DateTimeField()
    guid = models.CharField(max_length=100)

class Temperature(models.Model):
    temperature = models.FloatField()
    time = models.DateTimeField()
    guid = models.CharField(max_length=100)
